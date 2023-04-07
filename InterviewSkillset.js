var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
function descriptoradd(value) {
    return function (target, propertyKey, descriptor) {
        descriptor.enumerable = value;
    };
}
class obj {
    static nb_obj = 0;
    head;
    val;
    id;
    constructor(h) {
        this.head = h;
        this.val = [];
        ++obj.nb_obj;
    }
    Set_Identity(id) {
        this.id = id;
    }
    Add(val) {
        this.val.push(val);
    }
    Get(index) {
        return this.val[index];
    }
    Display() {
        console.log("id: " + this.id.id);
        console.log("hash: " + this.id.hash);
        console.log(this.head);
        [...this.val].forEach(v => {
            console.log(v);
        });
    }
}
__decorate([
    descriptoradd(false)
], obj.prototype, "Get", null);
function sortNumbers(a, b) {
    return a - b;
}
function sortCol(a, b) {
    if (a.head.toLowerCase() > b.head.toLowerCase()) {
        return 1;
    }
    else if (a.head.toLowerCase() < b.head.toLowerCase()) {
        return -1;
    }
    else {
        return 0;
    }
}
function Main() {
    var s = ["Regis", "Laurent", "Andre", "Joe", "Louis"];
    var tobj = [];
    for (var i = 0; i < s.length; ++i) {
        var o = new obj(s[i]);
        for (var j = 0; j < 10; ++j) {
            o.Add(Math.random() * 1000 + 1);
        }
        o.val.sort(sortNumbers);
        var h = ((Math.random() * 1000 + 1) * 1000000).toFixed(0);
        o.Set_Identity({ id: i, hash: h });
        tobj.push(o);
    }
    for (var i = 0; i < tobj.length; ++i) {
        tobj[i].Display();
    }
    tobj.sort(sortCol);
    console.log("---------------------------------");
    for (var i = 0; i < tobj.length; ++i) {
        tobj[i].Display();
    }
    console.log(tobj[0].Get(0));
    console.log(obj.nb_obj);
}
Main();
