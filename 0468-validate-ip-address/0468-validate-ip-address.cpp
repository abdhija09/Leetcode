class Solution {
public:
    string validIPAddress(string queryIP) {
        if (queryIP.find('.') != string::npos) {
            if (isIPv4(queryIP)) return "IPv4";
        }
        else if (queryIP.find(':') != string::npos) {
            if (isIPv6(queryIP)) return "IPv6";
        }

        return "Neither";
    }

    bool isIPv4(string s) {
        int n = s.size();
        int i = 0, parts = 0;

        while (i < n) {
            int num = 0, digits = 0;
            while (i < n && s[i] != '.') {
                if (!isdigit(s[i]))
                    return false;
                num = num * 10 + (s[i] - '0');
                digits++;

                if (digits > 3 || num > 255)
                    return false;

                i++;
            }
            if (digits == 0)
                return false;
            if (digits > 1 && s[i - digits] == '0')
                return false;

            parts++;

            if (i < n)
                i++;
        }

        return parts == 4 && s.back() != '.';
    }

    bool isIPv6(string s) {
        int n = s.size();
        int i = 0, parts = 0;

        while (i < n) {
            int digits = 0;

            while (i < n && s[i] != ':') {
                char c = s[i];

                if (!isdigit(c) &&
                    !(c >= 'a' && c <= 'f') &&
                    !(c >= 'A' && c <= 'F')) {
                    return false;
                }

                digits++;
                if (digits > 4)
                    return false;

                i++;
            }
            if (digits == 0)
                return false;
            parts++;

            if (i < n)
                i++;
        }

        return parts == 8 && s.back() != ':';
    }
};