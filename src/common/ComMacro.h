#ifndef COMMACRO_H
#define COMMACRO_H

#define WIN 0
#define LINUX 1
#define OSX 2

#define SET_DOMAIN_PARAMATER(_type_, _var_name_, _func_name_) \
    protected: _type_ _var_name_; \
    public: _type_ get##_func_name_(){return this->_var_name_;} \
    public: void set##_func_name_(_type_ value){this->_var_name_ = value;} \
    public: void append##_func_name_(_type_ value){this->_var_name_ += value;}



#endif // COMMACRO_H
