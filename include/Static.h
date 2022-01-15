#pragma once

#include "GameObject.h"

class Static : public GameObject {

public:

	using GameObject::GameObject;

	void setDelete();

	bool getDelete() const;


private:

	bool m_isDeleted = false;

};