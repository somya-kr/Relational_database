#include "rdb.h"

// Function to find the common attributes in two relations

Relation* Runion(const Relation* R1, const Relation* R2){
    if(R1->getNumAttrs() != R2->getNumAttrs()){
        cout<<"Not compatible!"<<endl;
        return nullptr;
    }
    if(R1->getAttrNames()!=R2->getAttrNames()){
        cout<<"Attribute names are not same."<<endl;
        cout<<"Can't take union!";
        return nullptr;
    }
    Relation* R = new Relation(R1->getNumAttrs(), R1->getAttrNames());
    for(auto r : R1->getRecords()){
        R->addRecord(new Record(*r));
    }
    int flag;
    for(auto r : R2->getRecords()){
        flag=0;
       for(auto r1 : R->getRecords()){
              if(*r1 == *r){
                flag=1;
                break;
              }
              if(flag==0){
                  R->addRecord(new Record(*r));
              }
       }
    }
    return R;
}

// Function to find the difference of two relations
Relation* Rdifference(const Relation* R1, const Relation* R2){
    if(R1->getNumAttrs() != R2->getNumAttrs()){
        return nullptr;
    }
    Relation* R = new Relation(R1->getNumAttrs(), R1->getAttrNames());
    int flag;
    for(auto r : R1->getRecords()){
        flag=0;
        for(auto r1 : R2->getRecords()){
            if(*r1 == *r){
                flag=1;
                break;
            }
        }
        if(flag==0){
            R->addRecord(new Record(*r));
        }
    }
   
    return R;
}

Relation* RcartesianProduct(const Relation* R1, const Relation* R2){
    vector<string> attrname;

    for(auto s : R1->getAttrNames()){
        attrname.push_back(s);
    }
    for(auto s : R2->getAttrNames()){
        attrname.push_back(s);
    }
    Relation* R = new Relation(R1->getNumAttrs()+R2->getNumAttrs(), attrname);
    for(auto r1 : R1->getRecords()){
        for(auto r2 : R2->getRecords()){
            vector<Attr*> attrs;
            for(int i=0; i<R1->getNumAttrs(); i++){
                attrs.push_back(r1->getAttribute(i));
            }
            for(int i=0; i<R2->getNumAttrs(); i++){
                attrs.push_back(r2->getAttribute(i));
            }
            R->addRecord(new Record(attrs));
        }
    }
    return R;
}
//Function to find the projection of a relation
Relation* Rprojection(const Relation* R, vector<string> attrnames){
    vector<int> attrinds;
    for(auto s : attrnames){
        // attrinds.push_back(R->getAttrInd(s));
        for(int i=0; i<R->getNumAttrs(); i++){
            if(R->getAttrNames()[i] == s){
                attrinds.push_back(i);
                break;
            }
        }
    }
    Relation* R_ = new Relation(attrinds.size(), attrnames);
    for(auto r : R->getRecords()){
        vector<Attr*> attrs;
        for(auto i : attrinds){
            attrs.push_back(r->getAttribute(i));
        }
        R_->addRecord(new Record(attrs));
    }
    return R_;
}

//Function to find the natural join of two relations
bool eval(tuple<string,char, Attr*> formula,const Record* r,const Relation* R){

    for(auto str: R->getAttrNames()){
        //cout<<"Attr- "<<str<<" ";
        //cout<<get<0>(formula)<<endl;
        //cout<<get<1>(formula)<<endl;
        if(get<0>(formula)==str){
            //cout<<"Match found"<<endl;
            if(get<1>(formula)=='='){
                //cout<<"Match found2"<<endl;
                if(*(r->getAttribute(R->getAttrInd(str)))==*(get<2>(formula))){
                    //cout<<"returning true"<<endl;
                    return true;
                }
            }
            else if(get<1>(formula)=='<'){
                if(*r->getAttribute(R->getAttrInd(str))<*get<2>(formula)){
                    return true;
                }
            }
            else if(get<1>(formula)=='>'){
                if(*r->getAttribute(R->getAttrInd(str))>*get<2>(formula)){
                    return true;
                }
            }
            else if(get<1>(formula)=='1'){
                if(*r->getAttribute(R->getAttrInd(str))>=*get<2>(formula)){
                    return true;
                }
            }
            else if(get<1>(formula)=='0'){
                if(*r->getAttribute(R->getAttrInd(str))<=*get<2>(formula)){
                    return true;
                }
            }
            else if(get<1>(formula)=='!'){
                if(*r->getAttribute(R->getAttrInd(str))!=*get<2>(formula)){
                    return true;
                }
            }
            else return false;
        }
    }
    return false;
}

//Function to check if a record satisfies a DNF formula
bool DNFCheck(DNFformula *f,const Relation* R, const Record* rec){
    bool ans_f= false;
   
    for(auto r: f->ops){
        bool ans= true;
        for(auto s: r){
            if(eval(s,rec,R)==false){
                ans=false;
                break;
            }
        }
        if(ans==true){
            ans_f=true;
            break;
        }
    }
    return ans_f;
}

//Function to find the selection of a relation
Relation* Rselection(const Relation* R1, DNFformula *f){
    Relation* R = new Relation(R1->getNumAttrs(),R1->getAttrNames());
    for(auto r : R1->getRecords()){
        if(DNFCheck(f,R1,r)){
            R->addRecord(new Record(*r));
        }
    }
    return R;
}


//Function to find the union of two relations
Relation* Rrename(Relation* R, string s1,string s2){
    vector<string> attrnames;
    for(auto s : R->getAttrNames()){
        if(s == s1){
            attrnames.push_back(s2);
        }
        else{
            attrnames.push_back(s);
        }
    }
    R->setAttrNames(attrnames);
    return R;
}



// int main(){
// vector<string> attrnames={"Name",	"EmpId"	,"DeptName"};
// Relation r(3,attrnames);
// // Original code
// Attr* a1=new stringAttribute("A");
// Attr* a2=new integerAttribute(10);
// Attr* a3=new stringAttribute("C");
// vector<Attr*> arr;
// arr.push_back(a1);
// arr.push_back(a2);
// arr.push_back(a3);

// // Renamed variables
// Attr* b1=new stringAttribute("B");
// Attr* b2=new integerAttribute(2);
// Attr* b3=new stringAttribute("D");
// vector<Attr*> brr;
// brr.push_back(b1);
// brr.push_back(b2);
// brr.push_back(b3);

// Attr* c1=new stringAttribute("E");
// Attr* c2=new integerAttribute(3);
// Attr* c3=new stringAttribute("C");
// vector<Attr*> crr;
// crr.push_back(c1);
// crr.push_back(c2);
// crr.push_back(c3);

// Attr* d1=new stringAttribute("G");
// Attr* d2=new integerAttribute(4);
// Attr* d3=new stringAttribute("D");
// vector<Attr*> drr;
// drr.push_back(d1);
// drr.push_back(d2);
// drr.push_back(d3);

// Attr* e1=new stringAttribute("I");
// Attr* e2=new integerAttribute(5);
// Attr* e3=new stringAttribute("C");
// vector<Attr*> err;
// err.push_back(e1);
// err.push_back(e2);
// err.push_back(e3);

// Attr* f1=new stringAttribute("K");
// Attr* f2=new integerAttribute(10);
// Attr* f3=new stringAttribute("C");
// vector<Attr*> frr;
// frr.push_back(f1);
// frr.push_back(f2);
// frr.push_back(f3);

// Record* rec1=new Record(arr);
// Record* rec2=new Record(brr);
// Record* rec3=new Record(crr);
// Record* rec4=new Record(drr);
// Record* rec5=new Record(err);
// Record* rec6=new Record(frr);
// //Record* rec1=new Record(arr);
// //Record r1(*rec);
// //Record* rec= new Record(r1);
// r.addRecord(rec1);
// r.addRecord(rec2);
// r.addRecord(rec3);
// r.addRecord(rec4);
// r.addRecord(rec5);
// r.addRecord(rec6);
// r.print();
// cout<<endl;


// DNFformula f;
// // f.ops= { { {{"Name","=","A"}}, {{"DeptName","=","C"}} }, { {{"Name","=","B"}}, {{"DeptName","=","D"}} } };

// tuple<string,char,Attr*> temp;
// get<0>(temp)="DeptName";
// get<1>(temp)='=';
// get<2>(temp)=new stringAttribute("C");

// list<tuple<string,char,Attr*>> l1;
// l1.push_back(temp);
// f.ops.push_back(l1);
// get<0>(temp)="EmpId";
// get<1>(temp)='>';
// get<2>(temp)=new integerAttribute(3);
// l1.push_back(temp);
// f.ops.push_back(l1);

// Relation* R=Rselection(&r,&f);
// R->print();
// cout<<endl;


// // vector<string> attr={"DeptName","Manager"};
// // Relation r1(2,attr);
// // Attr* aa1=new stringAttribute("C");
// // Attr* aa2=new stringAttribute("M");
// // vector<Attr*> arr1;
// // arr1.push_back(aa1);
// // arr1.push_back(aa2);
// // Attr* bb1=new stringAttribute("D");
// // Attr* bb2=new stringAttribute("N");
// // vector<Attr*> brr1;
// // brr1.push_back(bb1);
// // brr1.push_back(bb2);
// // Attr* cc1=new stringAttribute("E");
// // Attr* cc2=new stringAttribute("O");
// // vector<Attr*> crr1;
// // crr1.push_back(cc1);
// // crr1.push_back(cc2);
// // Attr* dd1=new stringAttribute("L");
// // Attr* dd2=new stringAttribute("P");
// // vector<Attr*> drr1;
// // drr1.push_back(dd1);
// // drr1.push_back(dd2);
// // Record* rec11=new Record(arr1);
// // Record* rec22=new Record(brr1);
// // Record* rec33=new Record(crr1);
// // Record* rec44=new Record(drr1);
// // r1.addRecord(rec11);
// // r1.addRecord(rec22);
// // r1.addRecord(rec33);
// // r1.addRecord(rec44);
// // r1.print();
// // cout<<endl;

// // Relation* r2=NaturalJoin(&r,&r1);
// // r2->print();


// return 0;

// }

// // //  vector<Attr *> attrs;
// // //     attrs.push_back(new integerAttribute(1));
// // //     attrs.push_back(new floatAttribute(2.0));
// // //     attrs.push_back(new stringAttribute("3"));
// // //     Record *rec = new Record(attrs);
// // //     Relation *rel = new Relation(3, {"a", "b", "c"});
// // //     rel->addRecord(rec);
// // //      vector<Attr *> attrs_;
// // //     attrs_.push_back(new integerAttribute(4));
// // //     attrs_.push_back(new floatAttribute(5.0));
// // //     attrs_.push_back(new stringAttribute("6"));
// // //     Record *rec_ = new Record(attrs_);
// // //      vector<Attr *> attrs1;
// // //      attrs1.push_back(new integerAttribute(3));
// // //     attrs1.push_back(new floatAttribute(9.0));
// // //     attrs1.push_back(new stringAttribute("7"));
// // //     Record *rec1 = new Record(attrs1);
// // //     Relation *rel_ = new Relation(3, {"d", "e", "f"});
// // //     rel_->addRecord(rec_);
// // //     rel_->addRecord(rec1);
// // //     Relation *rel2 = Rprojection(rel, {"a", "b"});
// // //     rel->print();
// // //     rel_->print();
// // //     rel2->print();
// //     return 0;
// // }