/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:53:49 by xamayuel          #+#    #+#             */
/*   Updated: 2024/02/22 19:14:10 by xamayuel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
class Contact
{
    public:
        void copyContactInfo(Contact source);
        
        void setFirstName(std::string newFirstName);
        void setLastName(std::string newLastName);
        void setNickname(std::string newNickname);
        void setPhoneNumber(std::string newPhoneNumber);
        void setSecret(std::string newSecret);
        
        std::string getFirstName(void) const;
        std::string getLastName(void) const;
        std::string getNickname(void) const;
        std::string getPhoneNumber(void) const;
        std::string getSecret(void) const;

    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string secret;
    

};
#endif