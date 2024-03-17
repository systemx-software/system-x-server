#include "User.h"
#include "DataBase/DataBase.h"


namespace systemx::data_base::api
{
    std::string User::GetName()
    {
        auto& pDataBase = DataBase::GetInstance();

        return pDataBase.QueryUnique(std::format("SELECT `name` FROM `users` WHERE `id` = {}", m_id))[0][0];
    }

    std::string User::GetStatus() const
    {
        return std::string();
    }

    std::string User::GetEmail() const
    {
        return std::string();
    }

} // namespace systemx::data_base