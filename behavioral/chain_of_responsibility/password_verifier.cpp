
#include "password_verifier.hpp"
#include "user_database.hpp"
#include "third_party/libbcrypt/bcrypt.h"

ResponseCode PasswordVerifier::handle(const Request& request){
	std::string password_hash = UserDatabase::GetPasswordHash(request.login);
	int result = bcrypt_checkpw(request.password.c_str(), password_hash.c_str());

	if(result != 0){
		return ResponseCode::BAD_PASSWORD;
	}

	if(next != nullptr){
		return next->handle(request);
	}
	return ResponseCode::SUCCESS;
}
