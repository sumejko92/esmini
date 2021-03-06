/* 
 * esmini - Environment Simulator Minimalistic 
 * https://github.com/esmini/esmini
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 * 
 * Copyright (c) partners of Simulation Scenarios
 * https://sites.google.com/view/simulationscenarios
 */

#pragma once

#include "Entities.hpp"


using namespace scenarioengine;

void Object::SetEndOfRoad(bool state, double time)
{
	if (state == true)
	{
		end_of_road_timestamp_ = time;
	}
	else
	{
		end_of_road_timestamp_ = 0.0;
	}
}

void Object::SetOffRoad(bool state, double time)
{
	if (state == true)
	{
		off_road_timestamp_ = time;
	}
	else
	{
		off_road_timestamp_ = 0.0;
	}
}

int Entities::addObject(Object* obj)
{
	obj->id_ = getNewId();
	object_.push_back(obj);
	return obj->id_;
}

void Entities::removeObject(int id) 
{
	for (size_t i = 0; i < object_.size(); i++) 
	{
		if (object_[i]->id_ == id) 
		{
			object_.erase(object_.begin() + i);
		}
	}
}

void Entities::removeObject(std::string name)
{
	for (size_t i = 0; i < object_.size(); i++) 
	{
		if (object_[i]->name_ == name) 
		{
			object_.erase(object_.begin() + i);
		}
	}
}

bool Entities::nameExists(std::string name)
{
	for (size_t i = 0; i < object_.size(); i++) 
	{
		if (object_[i]->name_ == name) 
		{
			return true;
		}
	}
	return false;
}
bool Entities::indexExists(int id) 
{
	for (size_t i = 0; i < object_.size(); i++) 
	{
		if (object_[i]->id_ == id) 
		{
			return false;
		}
	}
	return true;
}

int Entities::getNewId()
{
	int retint = 0;
	while (!indexExists(retint))
	{
		retint += 1;
	}
	return retint;
}