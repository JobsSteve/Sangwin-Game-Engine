#include "EventHandler.h"

EventHandler* EventHandler::inst;

EventHandler::EventHandler()
:events(new HashMap<SPtr<Queue<SPtr<Event> > > >),
 actions(new HashMap<SPtr<ArrayList<SPtr<Action> > > >())
{
    pthread_mutex_init(&postMutex,NULL);
    pthread_mutex_init(&updateMutex,NULL);
}


EventHandler::~EventHandler() {}


EventHandler* EventHandler::instance() {

    if(!inst) {
        inst = new EventHandler();
    }
    return inst;
}


void EventHandler::listen(const char* eventType, SPtr<Action> action) {

    if(!actions->containsKey(eventType)) {
        actions->put(eventType,SPtr<ArrayList<SPtr<Action> > >(new ArrayList<SPtr<Action> >()));
    }
    actions->get(eventType)->add(action);
}


void EventHandler::ignore(const char* eventType, SPtr<Action> action) {

    if(actions->containsKey(eventType)) {
        actions->get(eventType)->remove(action);
    }
}


void EventHandler::ignoreAll() {

    actions->clear();
}


void EventHandler::postEvent(const char* eventType, SPtr<Event> event) {

    pthread_mutex_lock(&postMutex);
    if(!events->containsKey(eventType)) {
        events->put(eventType,SPtr<Queue<SPtr<Event> > >(new Queue<SPtr<Event> >()));
    }
    if(event.get()) {
        events->get(eventType)->add(event);
    }
    pthread_mutex_unlock(&postMutex);
}


void EventHandler::update() {

    pthread_mutex_lock(&updateMutex);
    const char** keys = events->keySet();
    int size = events->size();
    for(int i=0; i<size; i++) {
        if(!events->get(keys[i])->isEmpty() && actions->containsKey(keys[i])) {
            for(int j=0; j<actions->get(keys[i])->size(); j++) {
                actions->get(keys[i])->get(j)->perform(events->get(keys[i]));
            }
        }
        events->get(keys[i])->clear();
    }
    pthread_mutex_unlock(&updateMutex);
}
