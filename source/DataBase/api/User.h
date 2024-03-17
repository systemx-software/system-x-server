#pragma once
#include <cstdint>
#include <string>
#include <optional>

namespace systemx::data_base::api
{
    class User
    {
    public:
        User(uint64_t id) : m_id(id) {};

        [[nodiscard]] std::optional<std::string> GetName() const;
        [[nodiscard]] std::optional<std::string> GetStatus() const;
        [[nodiscard]] std::optional<std::string> GetEmail() const;

    private:
        uint64_t m_id;
    };
    
} // namespace systemx::data_base
