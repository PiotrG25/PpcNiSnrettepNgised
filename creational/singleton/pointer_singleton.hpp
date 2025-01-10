
#ifndef CREATIONAL_POINTER_SINGLETON_HPP
#define CREATIONAL_POINTER_SINGLETON_HPP

#include <memory>
#include <mutex>

class PointerSingleton{
	public:
	PointerSingleton(const PointerSingleton&) = delete;
	PointerSingleton(const PointerSingleton&&) = delete;
	PointerSingleton& operator=(const PointerSingleton&) = delete;
	PointerSingleton& operator=(const PointerSingleton&&) = delete;
	~PointerSingleton() = default;
	
	static std::unique_ptr<PointerSingleton>& GetInstance();
	static const std::unique_ptr<PointerSingleton>& GetConstInstance();
	
	void SetValue(int value);
	int GetValue() const;
	
	private:
	PointerSingleton() = default;
	
	static std::unique_ptr<PointerSingleton> instance_;
	static std::once_flag initialization_flag_;
	int value_{};
};


#endif // CREATIONAL_POINTER_SINGLETON_HPP
