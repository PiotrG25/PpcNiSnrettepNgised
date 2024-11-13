
#ifndef STRUCTURAL_ADAPTER_AMERICAN_PLUG_HPP
#define STRUCTURAL_ADAPTER_AMERICAN_PLUG_HPP

class AmericanPlug{
	public:
	AmericanPlug(int id) : id_(id) {}
	virtual int ConnectToAmericanSocket() const {
		return id_;
	}
	private:
	int id_;
};

#endif // STRUCTURAL_ADAPTER_AMERICAN_PLUG_HPP
