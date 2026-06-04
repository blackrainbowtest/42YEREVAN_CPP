/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 10:44:05 by aramarak          #+#    #+#             */
/*   Updated: 2026/06/04 10:44:05 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream> 
# include <string>
# include "AForm.hpp"

// classes 
class Bureaucrat;

class ShrubberyCreationForm: public AForm 
{
    private:
        std::string     _target;
    public:
        // Constructors
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &src);
        // Destructors
        virtual ~ShrubberyCreationForm();
        // overload assignment operator
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
        // Methods
        virtual void	execute(Bureaucrat const &executor) const;
        // Getters
        const std::string	&getTarget(void) const;
        // Setters
};

// ostream Overload
std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &src);

#endif