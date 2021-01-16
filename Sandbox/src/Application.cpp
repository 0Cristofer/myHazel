//
// Created by crist on 15/01/2021.
//

namespace Hazel
{
    __declspec(dllimport) void Print();
}

int main()
{
    Hazel::Print();
    return 0;
}