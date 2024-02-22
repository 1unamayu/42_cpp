/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:47:02 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/22 18:53:38 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

class PhoneBook {
    public:
        PhoneBook(void);
	    ~PhoneBook(void);
        void add(void);
	    void search(void) const;
	    void printInstructions(void) const;
        
    private:
    
};
#endif