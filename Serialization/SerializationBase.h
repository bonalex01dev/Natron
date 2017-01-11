/* ***** BEGIN LICENSE BLOCK *****
 * This file is part of Natron <http://www.natron.fr/>,
 * Copyright (C) 2013-2017 INRIA and Alexandre Gauthier-Foichat
 *
 * Natron is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * Natron is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Natron.  If not, see <http://www.gnu.org/licenses/gpl-2.0.html>
 * ***** END LICENSE BLOCK ***** */

#ifndef SERIALIZATION_BASE_H
#define SERIALIZATION_BASE_H

#include "Serialization/SerializationFwd.h"

SERIALIZATION_NAMESPACE_ENTER;

/**
 * @brief Base class for serialization objects
 **/
class SerializationObjectBase
{
public:

    SerializationObjectBase()
    {

    }

    virtual ~SerializationObjectBase()
    {
        
    }

    /**
     * @brief Implement to write the content of the object to the emitter
     **/
    virtual void encode(YAML::Emitter& em) const = 0;

    /**
     * @brief Implement to read the content of the object from the yaml node
     **/
    virtual void decode(const YAML::Node& node) = 0;
};

/**
 * @brief Base class for serializable objects
 **/
class SerializableObjectBase
{
public:

    SerializableObjectBase()
    {

    }

    virtual ~SerializableObjectBase()
    {

    }
    
    /**
     * @brief Implement to save the content of the object to the serialization object
     **/
    virtual void toSerialization(SerializationObjectBase* serializationBase) = 0;

    /**
     * @brief Implement to load the content of the serialization object onto this object
     **/
    virtual void fromSerialization(const SerializationObjectBase& serializationBase) = 0;

};

SERIALIZATION_NAMESPACE_EXIT;

#endif // SERIALIZATION_BASE_H