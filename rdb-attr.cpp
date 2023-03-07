#include "rdb.h"
//For each attribute in R2, if it is not in common_attr, add it to attrs
bool integerAttribute ::operator==(const Attr &right)
{
    const integerAttribute *rightInt = dynamic_cast<const integerAttribute *>(&right);
    if (rightInt != nullptr)
    {
        return this->value == rightInt->value;
    }
    return false;
}

//For each attribute in R2, if it is not in common_attr, add it to attrs
bool integerAttribute ::operator!=(const Attr &right)
{
    return !(*this == right);
}

//For each attribute in R2, if it is not in common_attr, add it to attrs
bool integerAttribute ::operator<(const Attr &right)
{
    const integerAttribute *rightInt = dynamic_cast<const integerAttribute *>(&right);
    if (rightInt != nullptr)
    {
        return this->value < rightInt->value;
    }
    return false;
}

//For each attribute in R2, if it is not in common_attr, add it to attrs
bool integerAttribute ::operator<=(const Attr &right)
{
    return (*this < right || *this == right);
}

//For each attribute in R2, if it is not in common_attr, add it to attrs
bool integerAttribute ::operator>(const Attr &right)
{
    const integerAttribute *rightInt = dynamic_cast<const integerAttribute *>(&right);
    if (rightInt != nullptr)
    {
        return this->value > rightInt->value;
    }
    return false;
}

//For each attribute in R2, if it is not in common_attr, add it to attrs
bool integerAttribute ::operator>=(const Attr &right)
{
    return (*this > right || *this == right);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//For each attribute in R2, if it is not in common_attr, add it to attrs
bool floatAttribute ::operator==(const Attr &right)
{
    const floatAttribute *rightInt = dynamic_cast<const floatAttribute *>(&right);
    if (rightInt != nullptr)
    {
        return this->value == rightInt->value;
    }
    return false;
}

//For each attribute in R2, if it is not in common_attr, add it to attrs
bool floatAttribute ::operator!=(const Attr &right)
{
    return !(*this == right);
}

//For each attribute in R2, if it is not in common_attr, add it to attrs
bool floatAttribute ::operator<(const Attr &right)
{
    const floatAttribute *rightInt = dynamic_cast<const floatAttribute *>(&right);
    if (rightInt != nullptr)
    {
        return this->value < rightInt->value;
    }
    return false;
}

//For each attribute in R2, if it is not in common_attr, add it to attrs
bool floatAttribute ::operator<=(const Attr &right)
{
    return (*this < right || *this == right);
}

//For each attribute in R2, if it is not in common_attr, add it to attrs
bool floatAttribute ::operator>(const Attr &right)
{
    const floatAttribute *rightInt = dynamic_cast<const floatAttribute *>(&right);
    if (rightInt != nullptr)
    {
        return this->value > rightInt->value;
    }
    return false;
}

//For each attribute in R2, if it is not in common_attr, add it to attrs
bool floatAttribute ::operator>=(const Attr &right)
{
    return (*this > right || *this == right);
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//For each attribute in R2, if it is not in common_attr, add it to attrs
bool stringAttribute ::operator==(const Attr &right)
{
    const stringAttribute *rightStr = dynamic_cast<const stringAttribute *>(&right);
    if (rightStr != nullptr)
    {
        return this->value == rightStr->value;
    }
    return false;
}


//For each attribute in R2, if it is not in common_attr, add it to attrs
bool stringAttribute ::operator!=(const Attr &right)
{
    const stringAttribute *rightStr = dynamic_cast<const stringAttribute *>(&right);
    if (rightStr != nullptr)
    {
        return this->value != rightStr->value;
    }
    return false;
}


//For each attribute in R2, if it is not in common_attr, add it to attrs
bool stringAttribute ::operator<(const Attr &right)
{
    const stringAttribute *rightStr = dynamic_cast<const stringAttribute *>(&right);
    if (rightStr != nullptr)
    {
        return this->value < rightStr->value;
    }
    return false;
}


//For each attribute in R2, if it is not in common_attr, add it to attrs
bool stringAttribute ::operator<=(const Attr &right)
{
    return (*this < right || *this == right);
}


//For each attribute in R2, if it is not in common_attr, add it to attrs
bool stringAttribute ::operator>(const Attr &right)
{
    const stringAttribute *rightStr = dynamic_cast<const stringAttribute *>(&right);
    if (rightStr != nullptr)
    {
        return this->value > rightStr->value;
    }
    return false;
}


//For each attribute in R2, if it is not in common_attr, add it to attrs
bool stringAttribute ::operator>=(const Attr &right)
{
    return (*this > right || *this == right);
}