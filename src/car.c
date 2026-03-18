//
// Created by alalimov on 3/18/26.
//

#include "car.h"

static const struct _CarVtable car_vtable = { .dtor = car_dtor, .introduce = car_introduce };

void car_ctor(Car *this, const char *name)
{
    car_ctor_impl(&this->_car, name);
    this->_car.vtable = &car_vtable;
}

void car_ctor_impl(struct _CarImpl *self, const char *name)
{
    self->m_owner = malloc(13);
    snprintf(self->m_owner, 13, "%s", name);
}

void car_dtor(Car *this)
{
    car_dtor_impl(&this->_car);
}

void car_dtor_impl(struct _CarImpl *self)
{
    free(self->m_owner);
}

void car_introduce(Car *this)
{
    car_introduce_impl(&this->_car);
}

void car_introduce_impl(struct _CarImpl *self)
{
    log_debug("%s has a nice car\n", self->m_owner);
}