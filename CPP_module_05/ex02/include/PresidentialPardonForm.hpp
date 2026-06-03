/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 09:36:02 by aramarak          #+#    #+#             */
/*   Updated: 2026/05/25 09:36:02 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP 
# define PRESIDENTIALPARDONFORM_HPP 

# include <iostream> 
# include <string>
# include "AForm.hpp"

// classes 
class Bureaucrat;

class PresidentialPardonForm: public AForm 
{ 
    private: 
        std::string _target; 
    public:
        // Constructors
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &src);
        // Destructors
        virtual ~PresidentialPardonForm();
        // overload assignment operator
        PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
        // Methods
        virtual void	execute(Bureaucrat const &executor) const;
        // Getters
        const std::string	&getTarget(void) const;
        // Setters
};

// ostream Overload
std::ostream &operator<<(std::ostream &os, const PresidentialPardonForm &src);

#endif