class Employee{
public:
	Employee(string& name):name(name), comp(nullptr){}
	string getName(){return name;}
	void quit(){
		if(comp!=nullptr){
			comp->removeEmp(this);
			comp = nullptr
		}
	}
	void hired(Company* compA){comp = compA;}
private:
	string name;
	company* comp;
};
class Company{
public:
	Company(string& name): name(name){}
	void hire(Employee* emp){
		emp->hired(this);
		emps.push_back(emp);
	}
	Company& operator=(const Company& rhs){
		if(this != &rhs){
			for(size_t i = 0; i < emps.size(); ++i){
				delete emps[i];
			}
			name = rhs.name;
			emps.resize(rhs.emps.size());
			for(size_t i = 0; i < emps.size(); ++i){
				emps[i] = rhs.emps[i];
			}
		}
		return *this;
	}
	Employee* operator[](const string& person){
		for(size_t i = 0; i < emps.size(); ++i){
			if(emps[i]->getName() == person){
				return emps[i];
			}
		}
		return nullptr;
	}
priavte:
	string name;
	vector<Employee*> emps;
}