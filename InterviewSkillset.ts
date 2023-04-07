interface Identity {
    id: number;
    hash: string;
    opt?: string;
}

function descriptoradd(value: boolean) {
    return function (target: any, propertyKey: string, descriptor: PropertyDescriptor) {
        descriptor.enumerable = value;
    };
}

class obj<T>{
    static nb_obj:number = 0;
    head: string;
    val: T[];
    id: Identity;

    constructor(h:string){
        this.head = h;
        this.val = [];
        ++obj.nb_obj;
    }

    
    Set_Identity(id: Identity) {
        this.id = id;
    }

   
    Add(val: T) {
        this.val.push(val);
    }

    @descriptoradd(false)
    Get(index: number): T {
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



function sortNumbers(a, b) {
    return a - b;
}

function sortCol(a: obj<number>, b: obj<number>) {
    if (a.head.toLowerCase() > b.head.toLowerCase()) {
        return 1;
    } else if (a.head.toLowerCase() < b.head.toLowerCase()) {
        return -1;
    } else {
        return 0;
    }
}

function Main(){
    
    var s:string[] = ["Regis", "Laurent", "Andre", "Joe", "Louis"];
    var tobj: obj<number>[] = [];

    for (var i = 0; i < s.length; ++i){
        var o = new obj<number>(s[i]);
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