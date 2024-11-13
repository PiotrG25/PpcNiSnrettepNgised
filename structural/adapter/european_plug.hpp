
#ifndef STRUCTURAL_ADAPTER_EUROPEAN_PLUG_HPP
#define STRUCTURAL_ADAPTER_EUROPEAN_PLUG_HPP

class EuropeanPlug{
	public:
	EuropeanPlug(int id) : id_(id) {}
	virtual int ConnectToEuropeanSocket() const {
		return id_;
	}
	private:
	int id_;
};

#endif // STRUCTURAL_ADAPTER_EUROPEAN_PLUG_HPP
