#include <iostream>
#include <list>

using std::list;
int main()
{
    list<int> m_list;
    m_list.insert(m_list.begin(), 1);
    for(int i = 0; i < 10; i++){
        m_list.insert(m_list.end(), i);
    }
    for( auto iter = m_list.begin(); iter != m_list.end(); iter++ )
    {
        std::cout << *iter << std::endl;
    }
    std::cout << "Hello world" << std::endl;
    return 0;
}

