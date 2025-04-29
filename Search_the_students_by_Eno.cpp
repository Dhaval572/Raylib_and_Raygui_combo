#define RAYGUI_IMPLEMENTATION
#include <raylib.h>
#include <raygui.h>
#include <unordered_map>
#include <string>
using namespace std;

class StudentSearchApp
{
    unordered_map<int, string> students;
    char input[5] = ""; 
    char message[64] = "Enter last 4 digits";

    void searchStudent()
    {
        int num = atoi(input);
        if (input[0] == '\0' || num < 1000 || num > 9999)
        {
            snprintf(message, sizeof(message), "Invalid: needs 4 digits!");
            return;
        }

        auto it = students.find(static_cast<int>(num));
        if (it != students.end())
            snprintf(message, sizeof(message), "Student: %s", it->second.c_str());
        else
            snprintf(message, sizeof(message), "No student found!");
    }

public:
    StudentSearchApp()
    {
        const pair<int, const char *> data[] = {
            {7001, "ADROJA TWISHA BHUPENDRABHAI"},
            {7002, "AGRAVAT ARYAN NAYANBHAI"},
            {7003, "AJAGIYA YUG BHAVESHBHAI"},
            {7004, "APALIA VANSH HITESHBHAI"},
            {7005, "ARCHIV CHETAN VITHLANI"},
            {7006, "BAGDA HITEKSHA KARABHAI"},
            {7007, "BAGTHALIYA ANSH JAGDISHBHAI"},
            {7008, "BAGTHARIYA HIT VIJAYBHAI"},
            {7009, "BAKHADA KRISHA CHIRAG"},
            {7010, "BALDANIYA KARVENSHI UMESHBHAI"},
            {7011, "BELA NIKITA PALABHAI"},
            {7012, "BHADARKA PRIYENKUMAR GOPALBHAI"},
            {7013, "BHALIYA RIDDHI NARESHBHAI"},
            {7014, "BHARADVA MANALI VINAYBHAI"},
            {7015, "BHATTI REHANRJA BHIKHUBHAI"},
            {7016, "BHAYANI VEDANT DIVYESHBHAI"},
            {7017, "BHESADADIYA YASHVI MAHESHBHAI"},
            {7018, "BHUNDIYA DIP KALPESHBHAI"},
            {7019, "BHUVA CHANDAN MANSUKHBHAI"},
            {7020, "BORICHA PARAM SANDIPBHAI"},
            {7022, "CHAU JEETKUMAR MAHESHBHAI"},
            {7024, "CHAUHAN DEV KAUSHIKBHAI"},
            {7025, "CHAUHAN JANVI DHARMESHBHAI"},
            {7026, "CHAUHAN RAJVI KETANBHAI"},
            {7027, "CHAUHAN TULSI KAMLESHBHAI"},
            {7028, "CHAUHAN VISHWA RAJENDRABHAI"},
            {7029, "CHAVDA AAYUSHI KALPESHBHAI"},
            {7030, "CHAVDA NAIMISH"},
            {7031, "CHAVDA VISHESH HITESHBHAI"},
            {7032, "CHOTALIYA HARSH NITESHBHAI"},
            {7033, "CHUDASAMA MAMTABEN MANOJBHAI"},
            {7035, "DAV PRIYANSI BHAVESHBHAI"},
            {7036, "DAVE PURVA JESHANKARBHAI"},
            {7037, "DAVE SAUMYA REETESHBHAI"},
            {7038, "DHOLARIYA HIRENBHAI RAJESHBHAI"},
            {7039, "DHOLARIYA UTSAV BABUBHAI"},
            {7040, "DHORALIYA MANSI POPATBHAI"},
            {7041, "DHRANGDHARIYA SOHAM MANISHBHAI"},
            {7042, "MAKADIA DHRUV HIRENKUMAR"},
            {7043, "DOBARIYA SOHAM HITESHBHAI"},
            {7044, "DODIYA DHARMDEEP DHARMESHBHAI"},
            {7045, "DOSHI DISHA ATULBHAI"},
            {7046, "DOSHI PRIYANK JIGNESHBHAI"},
            {7047, "DUDHREJIYA YASH PRAGNESHBHAI"},
            {7048, "FATANIYA SMIT HITESHBHAI"},
            {7049, "GADARA RONAK MUKESHBHAI"},
            {7050, "GADHAVALA TALMIJ MUSTAKBHAI"},
            {7051, "GADHAVI HAPPY HIRENBHAI"},
            {7052, "GADOYA BRIJESH JIGNESHBHAI"},
            {7053, "GEDIYA JIGAR HASMUKHBHAI"},
            {7054, "GIRACH LIZA FIROZBHAI"},
            {7055, "GOHEL DEVANSHI SHAILESHBHAI"},
            {7056, "GOHIL MEET BHAVESHBHAI"},
            {7057, "GOKANI VRUSHTI VIPULBHAI"},
            {7058, "GONDALIYA HEMANGI DILIPBHAI"},
            {7059, "GONDALIYA YOGESH RASIKNHAI"},
            {7060, "GOSWAMI MITAL DEVENDRAGIRI"},
            {7061, "GOSWAMI PIYUSHGIRI MANOJGIRI"},
            {7062, "GOSWAMI SHUBHAM SANJAYBHAI"},
            {7064, "HADIYAL DARSHIL KETANBHAI"},
            {7065, "HADIYAL SAMIR NITINBHAI"},
            {7066, "HADIYEL KUMARIL SATISHBHAI"},
            {7067, "HINGU ISHA MANISHBHAI"},
            {7068, "JADAV HEMANSHI SANJAYBHAI"},
            {7070, "JADEJA YASHRAJSINH VIRENDRASINH"},
            {7071, "JANI VASU PRASHANT"},
            {7072, "JAVIYA AYUSH SATISHBHAI"},
            {7073, "JETHWA JAYVIRSINH PRADHYUMANSINH"},
            {7074, "JINJAVADIYA VIJAY BHARATBHAI"},
            {7075, "JOSHI HITANSHU DHANANJAYBHAI"},
        };

        for (const auto &p : data)
        {
            int last4 = static_cast<int>(p.first);
            students[last4] = p.second;
        }
    }

    void Update()
    {
        if (IsKeyPressed(KEY_ENTER) ||
            GuiButton({static_cast<float>(GetScreenWidth() / 2 - 40), static_cast<float>(GetScreenHeight() / 2 + 30), 80.0f, 30.0f}, "Search"))
        {
            searchStudent();
            input[0] = '\0';
        }
    }

    void Draw()
    {
        BeginDrawing();
        ClearBackground(BLACK);

        GuiTextBox({static_cast<float>(GetScreenWidth() / 2 - 100), static_cast<float>(GetScreenHeight() / 2 - 15), 200.0f, 30.0f},
                   input, sizeof(input), true);

        DrawText(message,
                 GetScreenWidth() / 2 - MeasureText(message, 20) / 2,
                 GetScreenHeight() / 2 + 70, 20,
                 strstr(message, "Invalid") ? RED : GREEN);

        DrawText("Search Division A students",
                 GetScreenWidth() / 2 - MeasureText("Search Division A students", 30) / 2,
                 100, 30, MAGENTA);

        EndDrawing();
    }

    void Run()
    {
        InitWindow(800, 600, "Search Student");
        SetTargetFPS(60);
        while (!WindowShouldClose())
        {
            Update();
            Draw();
        }
        CloseWindow();
    }
};

int main()
{
    StudentSearchApp app;
    app.Run();
    return 0;
}
