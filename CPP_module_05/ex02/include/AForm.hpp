/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 09:36:02 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/25 09:36:02 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;

class AForm
{
    protected:
        const std::string		_name;
        bool                    _is_signed;
        const int               _sign_req_grade;
        const int			    _exec_req_grade;

        static void             validateGrade(int grade);
    public:
        AForm(); // constructor
        AForm(const std::string name, const int sign_req_grade, const int exec_req_grade); // constructor with name and grades
        AForm(AForm const &copy); // copy constructor
        virtual ~AForm(); // descructor

    // overload assignment operator
        AForm & operator=(AForm const &src);

    // Getters
        const std::string&  getName(void) const;
        bool                getIsSigned(void) const;
        int                 getSignGrade(void)const;
        int                 getExecGrade(void)const;
    // Setters

    // Methods
        void beSigned(const Bureaucrat &signer);
    
    // Virtual Methods
        virtual void execute(Bureaucrat const & executor) const = 0;

    // Exceptions
    class GradeTooLowException : public std::exception
    {
        public:
            const char *what() const throw();
    };

    class GradeTooHighException : public std::exception
    {
        public:
            const char* what() const throw();
    };

    class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

// ostream Overload
std::ostream& operator<<(std::ostream& o, AForm const &a);

#endif