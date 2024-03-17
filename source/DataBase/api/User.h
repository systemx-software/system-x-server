#pragma once
#include <cstdint>
#include <string>


namespace systemx::data_base::api
{
    class User
    {
    public:
        User(uint64_t id) : m_id(id) {};

        [[nodiscard]] std::string GetName();
        [[nodiscard]] std::string GetStatus() const;
        [[nodiscard]] std::string GetEmail() const;

    private:
        uint64_t m_id;
    };
    
} // namespace systemx::data_base
