#include <iostream>

#include "door.h"

Open* Open::m_instance_ = 0;
Closed* Closed::m_instance_ = 0;
Locked* Locked::m_instance_ = 0;

Door::Door() {
	std::cout << "The current state of the door is closed" << std::endl;
	m_state_ = Closed::Instance();
}

void Door::ChangeState(State* state) {
	m_state_ = state;
}

void Door::PushPull() {
	m_state_->PushPull(this);
}

void Door::TurnKey() {
	m_state_->TurnKey(this);
}

void State::PushPull(Door* door) {

}

void State::TurnKey(Door* door) {

}

void State::ChangeState(Door* door, State *state) {
	door->ChangeState(state);
}

Open::Open() {

}

void Open::PushPull(Door* door) {
	std::cout << "The door is closing" << std::endl;

	ChangeState(door, Closed::Instance());
}

void Open::TurnKey(Door* door) {
	std::cout << "Nothing happens because the door is open" << std::endl;
}

State* Open::Instance() {
	if(m_instance_ == 0) {
		m_instance_ = new Open;
	}

	return m_instance_;
}

Closed::Closed() {

}

void Closed::PushPull(Door* door) {
	std::cout << "The door is opening" << std::endl;

	ChangeState(door, Open::Instance());
}

void Closed::TurnKey(Door* door) {
	std::cout << "The door is locking" << std::endl;

	ChangeState(door, Locked::Instance());
}

State* Closed::Instance() {
	if(m_instance_ == 0) {
		m_instance_ = new Closed;
	}

	return m_instance_;
}

Locked::Locked() {

}

void Locked::PushPull(Door* door) {
	std::cout << "Nothing happens because the door is locked" << std::endl;
}

void Locked::TurnKey(Door* door) {
	std::cout << "The door is unlocking" << std::endl;

	ChangeState(door, Closed::Instance());
}

State* Locked::Instance() {
	if(m_instance_ == 0) {
		m_instance_ = new Locked;
	}

	return m_instance_;
}