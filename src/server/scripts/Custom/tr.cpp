#include "ScriptPCH.h"
#include "Channel.h"
#include "Language.h"
 
class Chat_AntiAd : public PlayerScript
{
    public:
        Chat_AntiAd() : PlayerScript("Chat_AntiAd") {}
 
        void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg) { CheckMessage(player, msg); }
        void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Player* receiver) { CheckMessage(player, msg); }
        void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Group* group) { CheckMessage(player, msg); }
        void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Guild* guild) { CheckMessage(player, msg); }
        void OnChat(Player* player, uint32 /*type*/, uint32 lang, std::string& msg, Channel* channel) { CheckMessage(player, msg); }
 
        void CheckMessage(Player* player, std::string& msg)
        {
            std::string lowedMsg = msg;
            std::transform(lowedMsg.begin(), lowedMsg.end(), lowedMsg.begin(), tolower);
 
            // --- check msg for banned strings
 
            // banned strings (you can add other www domains)
            std::vector<std::string> bannedDNSs;
            bannedDNSs.push_back("http");
            bannedDNSs.push_back("com");
            bannedDNSs.push_back("net");
            bannedDNSs.push_back("org");
            bannedDNSs.push_back("ru");
            bannedDNSs.push_back("rondor");
            bannedDNSs.push_back("www.");
			bannedDNSs.push_back("epicworld");
			bannedDNSs.push_back("wow-lion");
			bannedDNSs.push_back("elgracia");
			bannedDNSs.push_back("uwow");
			bannedDNSs.push_back("wow-age");
			bannedDNSs.push_back("su");
			bannedDNSs.push_back("wow-fire");
			bannedDNSs.push_back("wow-qrsk");
			bannedDNSs.push_back("qwow");
			bannedDNSs.push_back("qrsk");
 
            for(std::vector<std::string>::iterator it = bannedDNSs.begin(); it != bannedDNSs.end(); ++it)
            {
                if (lowedMsg.find(*it) != std::string::npos)
                {
                    msg = "";
                    ChatHandler(player->GetSession()).PSendSysMessage("Неужели вы хотите порекламировать? Не стоит этого делать, злой якоб научит вас манерам!", it->c_str());
                    return;
                }
            }
 
            // --- check msg for IP
 
            // clear msg spaces
            std::string::size_type n = 0;
            while((n = lowedMsg.find(L' ', n)) != lowedMsg.npos)
                lowedMsg.erase(n, 1);
 
            // parsing for IP
            std::stringstream ss(lowedMsg);
            std::string domainLvlStr;
            for(uint16 domainLvl = 0; std::getline(ss, domainLvlStr, '.'); ++domainLvl)
            {
                // upon get the full address
                if(domainLvl >= 3)
                {
                    msg = "";
                    ChatHandler(player->GetSession()).PSendSysMessage("Неужели вы хотите порекламировать? Не стоит этого делать, злой якоб научит вас манерам!!");
                    return;
                }
 
                // for string manipulation
                std::string tempStr;
 
                if(domainLvl == 0)
                {
                    // catch upper domain
                    std::string::reverse_iterator it;
                    for(it = domainLvlStr.rbegin(); it != domainLvlStr.rend(); ++it)
                    {
                        if(!isdigit((int)*it))
                            break;
 
                        tempStr.push_back(*it);
                    }
                    domainLvlStr.assign(tempStr.rbegin(), tempStr.rend());
                }
                else if(domainLvl == 3)
                {
                    // catch lower domain
                    std::string::iterator it;
                    for(it = domainLvlStr.begin(); it != domainLvlStr.end(); ++it)
                    {
                        if(!isdigit((int)*it))
                            break;
 
                        tempStr.push_back(*it);
                    }
                    domainLvlStr = tempStr;
                }
 
                // is not number or empty. isdigit(atoi(domainLvlStr.c_str())) is incorrect
                if(domainLvlStr.find_last_not_of("0123456789") != std::string::npos || domainLvlStr.empty())
                    domainLvl = 0;
            }
        }
 
    private:
};
 
void AddSC_Chat_AntiAd()
{
    new Chat_AntiAd();
}