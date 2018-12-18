#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"

class MyController : public oatpp::web::server::api::ApiController {
    protected:
        MyController(const std::shared_ptr<ObjectMapper>& objectMapper)
            : oatpp::web::server::api::ApiController(objectMapper)
        {}
    public:

        static std::shared_ptr<MyController> createShared(const std::shared_ptr<ObjectMapper>& objectMapper = nullptr){
            return std::shared_ptr<MyController>(new MyController(objectMapper));
        }

        /**
         *  Begin ENDPOINTs generation ('ApiController' codegen)
         */
#include OATPP_CODEGEN_BEGIN(ApiController)

        ENDPOINT("GET", "/", root) {
            return createResponse(Status::CODE_200, "Hello World!");
        }

        /* put your endpoints here */

        /**
         *  Finish ENDPOINTs generation ('ApiController' codegen)
         */
#include OATPP_CODEGEN_END(ApiController)

};
