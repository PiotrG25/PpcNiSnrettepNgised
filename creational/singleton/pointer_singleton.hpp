
#ifndef CREATIONAL_POINTER_SINGLETON_HPP
#define CREATIONAL_POINTER_SINGLETON_HPP

class PointerSingleton{
	public:
	PointerSingleton(const PointerSingleton&) = delete;
	PointerSingleton(const PointerSingleton&&) = delete;
	PointerSingleton& operator=(const PointerSingleton&) = delete;
	PointerSingleton& operator=(const PointerSingleton&&) = delete;
	
	static PointerSingleton* const GetInstance();
	void SetValue(int value);
	int GetValue() const;
	
	private:
	PointerSingleton() = default;
	~PointerSingleton() = default;
	
	static PointerSingleton* instance_;
	int value_{};
};


#endif // CREATIONAL_POINTER_SINGLETON_HPP
