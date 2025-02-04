

#include <gtest/gtest.h>
#include "remote.hpp"
#include "radio.hpp"
#include "television.hpp"

TEST(BridgeTest, ExpectRemoteToCorrectlySwitchPowerOnAndOffForRadio){
	std::shared_ptr<Radio> device = std::make_shared<Radio>();
	Remote remote(device);
	
	EXPECT_FALSE(device->IsTurnedOn());
	remote.SwitchPower();
	EXPECT_TRUE(device->IsTurnedOn());
	remote.SwitchPower();
	EXPECT_FALSE(device->IsTurnedOn());
	remote.SwitchPower();
	EXPECT_TRUE(device->IsTurnedOn());
	remote.SwitchPower();
	EXPECT_FALSE(device->IsTurnedOn());
}

TEST(BridgeTest, ExpectRadioToHaveCorrectVolumeAfterTurningItUp){
	std::shared_ptr<Radio> device = std::make_shared<Radio>();
	Remote remote(device);
	
	remote.VolumeUp();
	EXPECT_EQ(11, device->GetVolume());
}

TEST(BridgeTest, ExpectRadioToHaveCorrectVolumeAfterTurningItDown){
	std::shared_ptr<Radio> device = std::make_shared<Radio>();
	Remote remote(device);
	
	remote.VolumeDown();
	EXPECT_EQ(9, device->GetVolume());
}

TEST(BridgeTest, ExpectRemoteToCorrectlySwitchPowerOnAndOffForTelevision){
	std::shared_ptr<Television> device = std::make_shared<Television>();
	Remote remote(device);
	
	EXPECT_FALSE(device->IsTurnedOn());
	remote.SwitchPower();
	EXPECT_TRUE(device->IsTurnedOn());
	remote.SwitchPower();
	EXPECT_FALSE(device->IsTurnedOn());
	remote.SwitchPower();
	EXPECT_TRUE(device->IsTurnedOn());
	remote.SwitchPower();
	EXPECT_FALSE(device->IsTurnedOn());
}

TEST(BridgeTest, ExpectTelevisionToHaveCorrectVolumeAfterTurningItUp){
	std::shared_ptr<Television> device = std::make_shared<Television>();
	Remote remote(device);
	
	remote.VolumeUp();
	EXPECT_EQ(21, device->GetVolume());
}

TEST(BridgeTest, ExpectTelevisionToHaveCorrectVolumeAfterTurningItDown){
	std::shared_ptr<Television> device = std::make_shared<Television>();
	Remote remote(device);
	
	remote.VolumeDown();
	EXPECT_EQ(19, device->GetVolume());
}
