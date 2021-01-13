class State;

class Door {
public:
	Door();

	void PushPull();
	void TurnKey();

private:
	friend class State;
	void ChangeState(State*);
	State *m_state_;
};

class State {
public:
	virtual void PushPull(Door*);
	virtual void TurnKey(Door*);
protected:
	void ChangeState(Door*, State*);
};

class Open : public State {
public:
	static State* Instance();

	virtual void PushPull(Door*);
	virtual void TurnKey(Door*);

protected:
	Open();

private:
	static Open* m_instance_;
};

class Closed : public State {
public:
	static State* Instance();

	virtual void PushPull(Door*);
	virtual void TurnKey(Door*);

protected:
	Closed();

private:
	static Closed* m_instance_;
};

class Locked : public State {
public:
	static State* Instance();

	virtual void PushPull(Door*);
	virtual void TurnKey(Door*);

protected:
	Locked();

private:
	static Locked* m_instance_;
};