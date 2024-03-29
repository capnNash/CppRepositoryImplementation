
/////////////////////////////////////////////////////////////////////////////////
// DcCore.cpp - Include the test stub showing the implementation of the        //
//                       NoSql database                                       //
// ver 1.0                                                                     //
// -----------------------------------------------------------------------     //
// copyright © Nishant Agrawal, 2018                                           //
// Source: Jim Fawcett, CSE687 - Object Oriented Design, Spring 2018          //                                                                   //
// -----------------------------------------------------------------------     //
// Language:    Visual C++, Visual Studio 2017                                //
// Platform:    Windows 7                                                      //
// Application: Spring Project,CSE 687,2018                                    //
// Author:      Nishant Agrawal, Syracuse University                           //
//              SUID: 595031520, nagraw01@syr.edu                              //
/////////////////////////////////////////////////////////////////////////////////
//
#include "DbCore.h"

#ifdef TEST_DBCORE
////----< test stub >----------------------------------------------------

using namespace NoSqlDb;

int main()
{
  Utilities::Title("Testing DbCore");

  DbCore<Payload> db;
  DbElement<Payload> demoElem;
  Payload demoLoad;
  demoLoad.FilePath("This is the file path...");
  std::vector<std::string> categ;
  categ.push_back("Cat 1");
  categ.push_back("Cat 2");

  demoLoad.Cat(categ);

  demoElem.name("Jim");
  demoElem.descrip("Instructor for CSE687");
  demoElem.dateTime(DateTime().now());
  demoElem.payLoad(demoLoad);
  db["Fawcett"] = demoElem;

  showHeader();
  showElem(demoElem);

  demoElem.name("Ammar");
  demoElem.descrip("TA for CSE687");
  db["Salman"] = demoElem;
  demoElem.name("Nishant");
  demoElem.descrip("student for CSE687");
  db["Nishant"] = demoElem;

  db["Fawcett"].children().push_back("Salman");
  db["Fawcett"].addChild("Nishant");
  db["Salman"].addChild("Nishant");
  db["Salman"].removeChild("Nishant");
  db.removeItem("Salman");
  std::cout << "\n  showing all the database elements:";
  showHeader();
  showDb(db);
  return 0;
}
#endif

