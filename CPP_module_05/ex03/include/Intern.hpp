/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramarak <aramarak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 14:36:02 by aramarak          #+#    #+#             */
/*   Updated: 2026/06/03 14:36:02 by aramarak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP 
# define INTERN_HPP 

# include <iostream> 
# include <string>
# include "AForm.hpp"

class Intern
{
    private:

    public:
        // Constructors
        Intern();
        Intern(const Intern &src);
        // Destructors
        ~Intern();
        // overload assignment operator
        Intern &operator=(const Intern &src);
        // Methods
        AForm *makeForm(const std::string &form, const std::string &target);
};

#endif