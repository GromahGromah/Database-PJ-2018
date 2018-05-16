#ifndef TABLES_H
#define TABLES_H

QString CreateTable_Users()
{
    QString res = "CREATE TABLE IF NOT EXISTS Users (";
    res = res + "Id" + " VARCHAR(16) NOT NULL,";
    res = res + "HashedPassword" + " VARCHAR(35) NOT NULL,";
    res = res + "Nick" + " VARCHAR(16),";
    res = res + "Motto" + " VARCHAR(50),";
    res = res + "Gender" + " VARCHAR(10),";
    res = res + "Solved" + " INT NOT NULL,";
    res = res + "Attempted" + " INT NOT NULL,";
    res = res + "OrzByOthers" + " INT NOT NULL,";
    res = res + "constraint pk_Users primary key(Id)";
    res = res + ")default charset = utf8;";
    return res;
}

QString CreateTable_Problems()
{
    QString res = "CREATE TABLE IF NOT EXISTS Problems (";
    res = res + "Id" + " INT NOT NULL AUTO_INCREMENT,";
    res = res + "Name" + " VARCHAR(40) NOT NULL,";
    res = res + "Description" + " VARCHAR(200),";
    res = res + "Source" + " VARCHAR(50),";
    res = res + "Answer" + " VARCHAR(50) NOT NULL,";
    res = res + "Hidden" + " INT NOT NULL,";
    res = res + "constraint pk_Problems primary key(Id)";
    res = res + ")default charset = utf8;";
    return res;
}

QString CreateTable_Status()
{
    QString res = "CREATE TABLE IF NOT EXISTS Status (";
    res = res + "Id" + " INT NOT NULL AUTO_INCREMENT,";
    res = res + "UserId" + " VARCHAR(16) NOT NULL,";
    res = res + "ProblemId" + " INT NOT NULL,";
    res = res + "SubmitAnswer" + " VARCHAR(50),";
    res = res + "Result" + " VARCHAR(50) NOT NULL,";
    res = res + "SubmitDate" + " VARCHAR(30) NOT NULL,";
    res = res + "constraint pk_Status primary key(Id),";
    res = res + "constraint fk_SU foreign key(UserId) references Users(Id),";
    res = res + "constraint fk_SP foreign key(ProblemId) references Problems(Id)";
    res = res + ")default charset = utf8;";
    return res;
}

#endif // TABLES_H
