#include <iostream>
using namespace std;

class AbstractEmployee
{
    virtual void askForPromotion() = 0;
};

class Employee : AbstractEmployee
{
private:
    string name;
    string company;
    int age;

public:
    Employee()
    {
    }
    Employee(string name, string company, int age)
    {
        this->name = name;
        this->company = company;
        this->age = age;
    }
    void getEmployeeInfo()
    {
        cout << "Name: " << this->name << endl;
        cout << "Company: " << this->company << endl;
        cout << "Age: " << this->age << endl;
    }
    void setName(string name)
    {
        this->name = name;
    }
    string getName()
    {
        return this->name;
    }
    void setAge(int age)
    {
        if (this->age < 18)
            this->age = age;
    }
    int getAge()
    {
        return this->age;
    }
    void askForPromotion()
    {
        if (this->age > 30)
            cout << this->name << "Promoted" << endl;
        else
            cout << this->name << "Not Promoted" << endl;
    }
    virtual void work()
    {
        cout << this->name << " is checking email, task backlog, performming tasks..." << endl;
    }
};

class Developer : public Employee
{
private:
    string FavariteProgrammingLanguage;

public:
    Developer()
    {
    }
    Developer(string name, string company, int age,
              string FavariteProgrammingLanguage) : Employee(name, company, age)
    {
        this->FavariteProgrammingLanguage =
            FavariteProgrammingLanguage;
    }
    void fixBug()
    {
        cout << getName() << " Fixed Bug using " << this->FavariteProgrammingLanguage << endl;
    }
};
class Teacher : public Employee
{
private:
    string Subject;

public:
    Teacher(string name, string company, int age, string subject)
        : Employee(name, company, age)
    {
        this->Subject = subject;
    }
    void prepareLesson()
    {
        cout << getName() << " is preparing" << Subject << " lesson" << endl;
    }
};

int main(int argc, char *argv[])
{
    Employee employee = Employee("Hai", "Google", 32);
    Developer developer = Developer("John", "Google", 25, "C++");
    Teacher teacher = Teacher("Jack", "elementry shool", 34, "History");
    Employee *e1 = &employee;
    Employee *e2 = &developer;
    Employee *e3 = &teacher;
    e1->askForPromotion();
    e2->work();
    return 0;
}