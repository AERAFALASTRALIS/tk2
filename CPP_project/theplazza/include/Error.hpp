/*
** EPITECH PROJECT, 2021
** Error
** File description:
** Error
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <iostream>

namespace Plazza {    
    class Error : virtual public std::exception {
    public :
        typedef enum ErrorCode_e {
            KITCHENFAILED,
            MAINARGSNB,
            MAINARGSTYPE,
            MUTEXFAIL,
            MUTEXLOCK,
            MUTEXUNLOCK,
            NO,
            PIPEFAILURE,
            PROCESSCREATE,
            PROCESSWAIT,
            UNDEFINEDPIZZA,
            UNDEFINEDCOMMAND,
            THREADSTART,
            THREADWAIT,
            THREADRUNTASK,
            THREADSTOP,
            WRONGFORMAT
        } Code;       
        Error(Code error, std::string const& phrase) throw();
        ~Error() throw();
        const char* what() throw();
    private:
        Code _code;
        std::string _msg;
    };
}

#endif /* !ERROR_HPP_ */
