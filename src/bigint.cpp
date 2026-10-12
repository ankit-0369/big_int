#include "bigint.h"

bool BigInt::is_valid(const std::string& text){
    //Check for the first character for the sign
    std::size_t i= 0;
    if(!text.empty() && (text[0] == '-' || text[0] == '+' )) i= 1;
    if(i == text.size()) return false; // means its just "" or "+" or "-" which is invalid

    for(; i<text.size(); i++){

        if(text[i]<'0' || text[i]>'9') return false;
    }

    return true;
}

void BigInt::trim(){
    while(!limbs_.empty() && limbs_.back() == 0) limbs_.pop_back(); //removing all leading zeroes
    if(limbs_.empty()) neg_= false; //making sure no negative zeroes
}

BigInt::BigInt(const std::string&text){

    if(!is_valid(text)) throw std::invalid_argument("BigInt: invalid number string");
    std::size_t start= 0;
    bool negative= false;
    if(text[0] == '-' || text[0] == '+'){
        negative= (text[0] == '-');
        start= 1;
    }

    //have to make lump of 9 or less character and put it into the limbs_
    for(std::size_t end= text.size(); end>start;){
        std::size_t begin= (end - start > kBaseDigits) ? (end - kBaseDigits) : start;
        std::uint32_t limb=0;
        for(std::size_t i= begin; i <end; i++){
            limb= limb*10 + static_cast<std::uint32_t>(text[i] - '0');
        }

        limbs_.push_back(limb);
        end= begin;
    }

    neg_= negative;
    trim();

}


std::string BigInt::to_string() const {
    if (limbs_.empty()) return "0";

    std::string out = neg_ ? "-" : "";
    out += std::to_string(limbs_.back());             // top limb: no zero padding

    for (std::size_t i = limbs_.size() - 1; i-- > 0;) {
        std::string chunk = std::to_string(limbs_[i]);
        out.append(kBaseDigits - chunk.size(), '0');  // inner limbs: pad to 9 digits
        out += chunk;
    }
    return out;
}
