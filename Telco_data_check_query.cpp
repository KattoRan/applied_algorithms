#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+7;

map<string,int> m, m_time;
int total = 0;
int check_phone = 1;

int toseconds(string s_time)
{
    int h,m,s;
    char c;
    stringstream ss(s_time);
    ss >> h >> c >> m >> c >> s;
    return h*3600 + m*60 + s;
}
int check_time(string startTime, string endTime)
{
    return toseconds(endTime) - toseconds(startTime);
}
int main()
{
    string call,phone,tophone,date,s_time,e_time;
    while (1)
    {
        cin >> call;
        if (call == "#") break;
        total++;
        cin >> phone >> tophone >> date >> s_time >> e_time;
        m[phone]++;
        m_time[phone] += check_time(s_time,e_time);
        if (phone.size() != 10 || tophone.size() != 10 || !std::all_of(phone.begin(), phone.end(), ::isdigit) || !std::all_of(tophone.begin(), tophone.end(), ::isdigit))
            check_phone = 0;
    }
    while(1)
    {
        string s,t;
        cin >> s;
        if (s == "#") break;
        if (s == "?check_phone_number") cout << check_phone << endl;
        else
            if (s == "?number_total_calls") cout << total << endl;
            else
                if (s == "?number_calls_from")
                {
                    cin >> phone;
                    cout << m[phone] << endl;
                }
                else
                {
                    cin >> phone;
                    cout << m_time[phone] << endl;
                }
    }
    return 0;
}
