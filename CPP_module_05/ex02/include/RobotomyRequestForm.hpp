/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:44:05 by aramarak          #+#    #+#             */
/*   Updated: 2026/06/04 10:44:05 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream> 
# include <string>
# include <cstdlib>
# include "AForm.hpp"

// classes 
class Bureaucrat;

class RobotomyRequestForm: public AForm 
{
    private:
        std::string     _target;
    public:
        // Constructors
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &src);
        // Destructors
        virtual ~RobotomyRequestForm();
        // overload assignment operator
        RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
        // Methods
        virtual void	execute(Bureaucrat const &executor) const;
        // Getters
        const std::string	&getTarget(void) const;
        // Setters
};

// ostream Overload
std::ostream &operator<<(std::ostream &os, const RobotomyRequestForm &src);

#endif