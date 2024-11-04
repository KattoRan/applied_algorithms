#include <bits/stdc++.h>
using namespace std;

// Hàm tính thời gian kết thúc chiếu phim
string cal_time(string s_time, string dur)
{
    int s_hour, s_minute, dur_hour, dur_minute;
    sscanf(s_time.c_str(), "%d:%d", &s_hour, &s_minute);
    sscanf(dur.c_str(), "%d:%d", &dur_hour, &dur_minute);

    int e_hour = s_hour + dur_hour;
    int e_minute = s_minute + dur_minute;

    if (e_minute >= 60)
    {
        e_hour += e_minute / 60;
        e_minute = e_minute % 60;
    }

    ostringstream oss;
    oss << setfill('0') << setw(2) << e_hour << ":" << setw(2) << e_minute;
    return oss.str();
}

// Hàm kiểm tra giới hạn thời gian cho trẻ em và thanh niên
string check_Restriction_time(string age, string e_time, int adult_ok)
{
    int e_hour, e_minute;
    sscanf(e_time.c_str(), "%d:%d", &e_hour, &e_minute);

    if (age == "Child" && e_hour >= 16 && !adult_ok)
    {
        return "An adult companion is required for admission to this movie.";
    }
    if (age == "Young" && e_hour >= 18 && !adult_ok)
    {
        return "An adult companion is required for admission to this movie.";
    }
    return "";
}

// Hàm kiểm tra giới hạn độ tuổi
string Check_Restriction_age(string age, string movie_rating, int adult_ok)
{
    if (movie_rating == "R18+" && age != "Adult")
    {
        return "You cannot view this movie due to age restrictions.";
    }
    if (movie_rating == "PG-12" && age == "Child")
    {
        if (adult_ok) return "An adult companion is required for admission to this movie.";
        else return "You cannot view this movie due to age restrictions.";
    }

    return "";
}

// Hàm kiểm tra vị trí ghế ngồi cho trẻ em
string Check_Restriction_seat(string age, string seat)
{
    if (age == "Child")
    {
        char row = seat[0];
        if (row >= 'J' && row <= 'L')
        {
            return "You cannot use that seat with the ticket type you selected.";
        }
    }
    return "";
}

// Hàm tính toán và kiểm tra xem có thể mua vé không
void process (vector<string> tickets)
{
    int adult_ok = 0;
    string movie_rating, start_time, duration;
    vector<int> prices;
    vector<string> error;

    for (auto ticket : tickets)
    {
        stringstream ss(ticket);
        string age, rating, s_time, dur, seat;

        getline(ss, age, ',');
        getline(ss, rating, ',');
        getline(ss, s_time, ',');
        getline(ss, dur, ',');
        getline(ss, seat, ',');

        string error_mess;
        if (age == "Adult") adult_ok = 1;

        // Kiểm tra giới hạn độ tuổi
        string Restriction_age = Check_Restriction_age(age, rating, adult_ok);
        if (Restriction_age.size())
        {
            error_mess+=Restriction_age;
        }

        // Kiểm tra giới hạn ghế ngồi
        string Restriction_seat = Check_Restriction_seat(age, seat);
        if (Restriction_seat.size())
        {
            if (error_mess.size()) error_mess += ",";
            error_mess+=Restriction_seat;
        }

        // Tính toán thời gian kết thúc
        string e_time = cal_time(s_time, dur);

        // Kiểm tra giới hạn thời gian
        string Restriction_time = check_Restriction_time(age, e_time, adult_ok);
        if (Restriction_time.size())
        {
            if (error_mess.size()) error_mess += ",";
            error_mess+=Restriction_time;
        }

        if (error_mess.size())
        {
            error.push_back(error_mess);
            continue;
        }


        // Tính giá vé
        if (age == "Adult") prices.push_back(1800);
        else if (age == "Young") prices.push_back(1200);
        else if (age == "Child") prices.push_back(800);

    }

    // Nếu không có lỗi thì xuống dòng
    if (!error.empty())
    {
        for (auto mess : error) cout << mess << "\n";
        return;
    }
    // Trả về tổng giá tiền
    for (int price : prices) cout << price << " yen\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("sample.inp", "r", stdin);
    //freopen("sample.out", "w", stdout);

    vector<string> tickets;
    string line;
    while (getline(cin, line) && !line.empty())
    {
        tickets.push_back(line);
    }

    process(tickets);
    return 0;
}
