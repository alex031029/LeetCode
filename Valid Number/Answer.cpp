class Solution {
public:
    bool isNumber(string s) {
        enum
        {
            START,
            INTEGER,
            NOT_NUMERIC,
            FLOAT,
            FLOAT_TEMP,
            SCIENTIC_NOTATION,
            SCIENTIC_NOTATION_TEMP,
            SCIENTIC_NOTATION_TEMP_SIGN,
            NUMERIC,
        };
        int i,j;
        for(i=0;i<s.size()&&s[i]==' ';i++)
            ;
        for(j=s.size()-1;j>=0&&s[j]==' ';j--)
            ;
        string subs=s.substr(i,j-i+1);
        cout<<"subs:"<<subs<<endl;
        if(subs.size()==0||subs=="."||subs=="+."||subs=="-.")
            return false;
        int state=START;
        if(subs[0]=='+'||subs[0]=='-')
            i=1;
        else
            i=0;
        for(;i<subs.size();i++)
        {
            char input=subs[i];
            cout<<"state:"<<state<<endl;
            switch(state)
            {
                case START:
                    if(input>='0'&&input<='9')
                        state=INTEGER;
                    else if(input=='.')
                        state=FLOAT_TEMP;
                    else
                        state=NOT_NUMERIC;
                    break;
                case INTEGER:
                    //if(!((input>='0'&&input<='9')||input=='e'||input=='.'))
                    //    state=NOT_NUMBERIC;
                    if(input>='0'&&input<='9')
                        state=INTEGER;
                    else if(input=='e')
                        state=SCIENTIC_NOTATION_TEMP;
                    else if(input=='.')
                        state=FLOAT;
                    else
                        state=NOT_NUMERIC;
                    break;
                case FLOAT_TEMP:
                    if(input>='0'&&input<='9')
                        state=FLOAT;
                    //else if(input=='e')
                    //    state=SCIENTIC_NOTATION_TEMP;
                    else
                        state=NOT_NUMERIC;
                    break;
                case FLOAT:
                    if(input>='0'&&input<='9')
                        state=FLOAT;
                    else if(input=='e')
                        state=SCIENTIC_NOTATION_TEMP;
                    else
                        state=NOT_NUMERIC;
                    break;
                case SCIENTIC_NOTATION_TEMP:
                    if(input>='0'&&input<='9')
                        state=SCIENTIC_NOTATION;
                    else if(input=='+'||input=='-')
                        state=SCIENTIC_NOTATION_TEMP_SIGN;
                    else
                        state=NOT_NUMERIC;
                    break;
                case SCIENTIC_NOTATION_TEMP_SIGN:
                    if(input>='0'&&input<='9')
                        state=SCIENTIC_NOTATION;
                    else
                        state=NOT_NUMERIC;
                    break;
                case SCIENTIC_NOTATION:
                    if(input>='0'&&input<='9')
                        state=SCIENTIC_NOTATION;
                    else 
                        state=NOT_NUMERIC;
                    break;
                case NOT_NUMERIC:
                    return false;
            }
        }
        cout<<"state:"<<state<<endl;
        if(state==NOT_NUMERIC||state==SCIENTIC_NOTATION_TEMP||state==FLOAT_TEMP||state==SCIENTIC_NOTATION_TEMP_SIGN)
            return false;
        return true;
    }
};
