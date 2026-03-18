//
// Created by alalimov on 3/18/26.
//

#include "car.h"
#include "awesome_car.h"

static const struct _CarVtable awesome_car_vtable = { .dtor = (void (*)(Car *)) awesome_car_dtor, .introduce = (void (*)(
        Car *)) awesome_car_introduce};

void awesome_car_ctor(AwesomeCar *this, const char *name, const char *brand)
{
    car_ctor_impl(&this->_car, name);
    awesome_car_ctor_impl(&this->_awesome_car, name, brand);
    this->_car.vtable = &awesome_car_vtable;
}

void awesome_car_ctor_impl(struct _AwesomeCarImpl *self, const char *name, const char *brand)
{
    self->m_brand = malloc(17);
    snprintf(self->m_brand, 17, "%s", brand);
}

void awesome_car_dtor(AwesomeCar *this)
{
    awesome_car_dtor_impl(&this->_awesome_car);
    car_dtor_impl(&this->_car);
}

void awesome_car_dtor_impl(struct _AwesomeCarImpl *self)
{
    free(self->m_brand);
}

void awesome_car_introduce(AwesomeCar *this)
{
    awesome_car_introduce_impl(&this->_awesome_car);
}

void awesome_car_introduce_impl(struct _AwesomeCarImpl *self)
{
    log_debug("What a nice %s!\n", self->m_brand);
}
