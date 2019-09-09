#include <iostream>
#include <sqlite3.h>
#include <curl/curl.h>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <map>
#include "include/rapidjson/document.h"
#include "CurlAgent.h"
#include "JsonString.h"


#define APP_API_REST_URL ("http://localhost/api/product/")

CurlAgent curl(APP_API_REST_URL);


using namespace std;
using namespace rapidjson;


static int callback(void *NotUsed, int argc, char **argv, char **szColName)
{
    for(int i = 0; i < argc; i++)
    {
        cout << szColName[i] << " = " << argv[i] << endl;
    }

    cout << "\n";

    return 0;
}




int main()
{
    string jsonRequest_str;
    Document jsonDoc;


    jsonRequest_str = curl.sendGetRequest("read_cartao.php");


    if (curl.res == CURLE_OK) {
        const char *jsonRequest = jsonRequest_str.c_str();

        jsonDoc.Parse(jsonRequest);


        const Value& c = jsonDoc["cartoes"];
        assert(c.IsArray()); // attributes is an array
        for (rapidjson::Value::ConstValueIterator itr = c.Begin(); itr != c.End(); ++itr) {
            const rapidjson::Value& attribute = *itr;
            assert(attribute.IsObject()); // each attribute is an object
            for (rapidjson::Value::ConstMemberIterator itr2 = attribute.MemberBegin(); itr2 != attribute.MemberEnd(); ++itr2) {
                std::cout << itr2->name.GetString() << " : " << itr2->value.GetString() << std::endl;
            }

            cout<<endl;
        }


    }else {

        cout<<"Falha na conexão"<<endl;
    }














/*

    sqlite3 *db_em_uso;
    sqlite3 *db_att;
    char *szErrMsg = 0;

    // open database
    int rc_em_uso = sqlite3_open("DB_uso.db", &db_em_uso);
    int rc_att = sqlite3_open("DB_att.db", &db_att);

    if(rc_em_uso)
    {
        cout << "Can't open DB_uso database\n";
    } else {
        cout << "Open database DB_uso successfully\n";
    }

    if(rc_att)
    {
        cout << "Can't open DB_att database\n";
    } else {
        cout << "Open database DB_att successfully\n";
    }

    // prepare our sql statements
    const char *pSQL[6];
    pSQL[0] = "CREATE TABLE IF NOT EXISTS Employee(Firstname varchar(30), Lastname varchar(30), Age smallint)";
    pSQL[1] = "INSERT INTO Employee(Firstname, Lastname, Age) VALUES ('Woody', 'Alan', 45)";
    pSQL[2] = "INSERT INTO Employee(Firstname, Lastname, Age) VALUES ('Carlos', 'Magno', 53)";
    pSQL[3] = "INSERT INTO Employee(Firstname, Lastname, Age) VALUES ('Micheal', 'Bay', 38)";
    pSQL[4] = "SELECT * FROM Employee";
    pSQL[5] = "DELETE FROM Employee";

    // prepare our sql statements
    const char *pSQL_2[6];
    pSQL_2[0] = "CREATE TABLE IF NOT EXISTS Employee(Firstname varchar(30), Lastname varchar(30), Age smallint)";
    pSQL_2[1] = "INSERT INTO Employee(Firstname, Lastname, Age) VALUES ('Bob', 'Ross', 40)";
    pSQL_2[2] = "INSERT INTO Employee(Firstname, Lastname, Age) VALUES ('Elon', 'Musk', 33)";
    pSQL_2[3] = "INSERT INTO Employee(Firstname, Lastname, Age) VALUES ('Mattheus', 'Soares', 23)";
    pSQL_2[4] = "SELECT * FROM Employee";
    pSQL_2[5] = "DELETE FROM Employee";

    // execute sql
    cout << endl << "DB_uso: " << endl << endl;
    for(int i = 0; i < 6; i++)
    {
        rc_em_uso = sqlite3_exec(db_em_uso, pSQL[i], callback, 0, &szErrMsg);
        if(rc_em_uso != SQLITE_OK)
        {
            cout << "SQL Error: " << szErrMsg << endl;
            sqlite3_free(szErrMsg);
            break;
        }
    }

    // execute sql
    cout << endl << "DB_att: " << endl << endl;
    for(int i = 0; i < 6; i++)
    {
        rc_att = sqlite3_exec(db_att, pSQL_2[i], callback, 0, &szErrMsg);
        if(rc_att != SQLITE_OK)
        {
            cout << "SQL Error: " << szErrMsg << endl;
            sqlite3_free(szErrMsg);
            break;
        }
    }

    // close database
    if(db_em_uso)
    {
        sqlite3_close(db_em_uso);
    }

    // close database
    if(db_att)
    {
        sqlite3_close(db_att);
    }


 */

    return 0;
}