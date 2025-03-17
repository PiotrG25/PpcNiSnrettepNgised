
#include "login_finder.hpp"
#include "user_database.hpp"

ResponseCode LoginFinder::handle(const Request& request){
	if(not UserDatabase::IsUser(request.login)){
		return ResponseCode::BAD_LOGIN;
	}
	
	if(next != nullptr){
		return next->handle(request);
	}
	return ResponseCode::SUCCESS;
}
