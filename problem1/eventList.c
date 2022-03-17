#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
    EventList *eventList = malloc(sizeof(EventList));
    eventList->head = NULL;
    eventList->last = NULL;
    eventList->isEmpty = 0;
    return eventList;
}

void DestroyEventList(EventList *this)
{

    free(this);
}

Event *SearchEvent(EventList *this, char *name)
{
    Event *r = this->head;
    if (this->isEmpty != 0)
    {

        while (r != NULL)
        {
            if (*(r->eventName + 2) == *(name + 2) && *(r->eventName + 3) == *(name + 3))
            {
                return r;
            }
            r = r->next;
        }
    }
    else
    {
        return NULL;
    }

    return NULL;
}

void AddEvent(EventList *this, Event *event)
{

    Event *r = this->head;

    if (this->isEmpty != 0)
    {
        while (r != NULL)
        {
            if (*(r->eventName + 2) == *(event->eventName + 2) && *(r->eventName + 3) == *(event->eventName + 3))
            {
                return;
            }
            r = r->next;
        }
        this->last->next = event;
        this->last = event;
    }
    else
    {
        this->head = event;
        this->last = event;
        this->isEmpty = 1;
    }
}

void RemoveEvent(EventList *this, char *name)
{
     
        Event bandera;
        Event *r = this->head;
        int8_t contador = 0;
        if (this->isEmpty != 0)
        {

            do
            {
                if (*(this->head->eventName + 2) == *(name + 2))
                {
                    DestroyEvent(this->head);
                    this->head = this->head->next;
                    break;
                }
                else if (*(r->next->eventName + 2) == *(name + 2))
                {
                    DestroyEvent(r->next);
                    r->next = r->next->next;
                    break;
                }
                else
                {
                    contador = contador + 1;
                    if (contador == 7)
                    {

                        return;
                    }
                }

                r = r->next;
                contador = contador + 1;

                /*if (recorrido == NULL)
                {
                    while (contador != 0)
                    {
                        if (!(*(new_recorrido->eventName + 2) == *(name + 2) && *(new_recorrido->eventName + 3) == *(name + 3)))
                        {
                            return;
                        }
                        new_recorrido = new_recorrido->next;
                        contador = contador - 1;
                    }
                }*/

            } while (r != NULL);

            if (this->head == NULL)
            {
                this->isEmpty = 0;
            }
        }
        else
        {
            return;
        }
    }
}

void ListEvents(EventList *this)
{
    // imprime esto si la lista está vacía

    Event *r = this->head;
    // int8_t contador = 0;

    if (this->isEmpty != 0)
    {

        while (r != NULL)
        {

            printf("%s\n", r->eventName);
            r = r->next;
        }
    }
    else
    {
        printf("empty\n");
    }
}
