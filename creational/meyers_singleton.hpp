
#ifndef CREATIONAL_MEYERS_SINGLETON_HPP
#define CREATIONAL_MEYERS_SINGLETON_HPP

class MeyersSingleton{
	public:
	MeyersSingleton(const MeyersSingleton&) = delete;
	MeyersSingleton(const MeyersSingleton&&) = delete;
	MeyersSingleton& operator=(const MeyersSingleton&) = delete;
	MeyersSingleton& operator=(const MeyersSingleton&&) = delete;
	
	static MeyersSingleton& GetInstance();
	void SetValue(int value);
	int GetValue() const;
	
	private:
	MeyersSingleton() = default;
	~MeyersSingleton() = default;
	
	int value_;
};

#endif // CREATIONAL_MEYERS_SINGLETON_HPP
