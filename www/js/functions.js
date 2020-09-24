"use strict";

let firstValueString = "";
let secondValueString = "";
let firstValue = 0.0;
let secondValue = 0.0;
let isFirstValue = false;
let isSecondValue = false;
let isNumberPressed = false;
let isSecondPressed = false;

let numberShow = 0.0;

let result = 0.0;
let stringResult = "";
let lastOperator = "";

function updateResult(op){

    switch(op){
        case "+":
            result += secondValue;
            break;
        case "-":
            result -= secondValue;
            break;
        case "*":
            result *= secondValue;
            break;
        case "/":
            result /= secondValue;
            break;
        default:
            break;
    }

}

function updateNumber(x){

    if(!isNaN(x))
         isNumberPressed = true;

    if(!isFirstValue){
            firstValueString = firstValueString.concat(x);
            firstValue = parseFloat(firstValueString);
            numberShow = parseFloat(firstValueString);
    }
    else{
        isSecondPressed = true;
        secondValueString = secondValueString.concat(x);
        secondValue = parseFloat(secondValueString);
        numberShow = parseFloat(secondValueString);
    }
 
    if(!isNaN(x))
         document.getElementById("input_2").innerHTML = numberShow;
    else
         document.getElementById("input_2").innerHTML = "";

}

function updateOperator(oper){

    if(isNumberPressed){

        if(!isFirstValue){
            isFirstValue = true;
            result = firstValue;
            numberShow = firstValue;
        }
        else{
            if(isSecondPressed){
                isSecondValue = true;
                numberShow = secondValue;
            }
        }

    }
    else
         return;
    
    if(isFirstValue && isSecondValue){
            updateResult(lastOperator);
            secondValueString = "";
            secondValue = 0.0;
            isSecondPressed = false;
            firstValue = result;
    }

    lastOperator = oper;
    stringResult = stringResult.concat(numberShow);
    stringResult = stringResult.concat(" ");
    stringResult = stringResult.concat(oper);
    stringResult = stringResult.concat(" ");
    document.getElementById("input_1").innerHTML = stringResult;

}

function setZero(){
    let x = 0;
    updateNumber(x);
}

function setOne(){
    let x = 1;
    updateNumber(x);
}

function setTwo(){
    let x = 2;
    updateNumber(x);
}

function setThree(){
    let x = 3;
    updateNumber(x);
}

function setFour(){
    let x = 4;
    updateNumber(x);
}

function setFive(){
    let x = 5;
    updateNumber(x);
}

function setSix(){
    let x = 6;
    updateNumber(x);
}

function setSeven(){
    let x = 7;
    updateNumber(x);
}

function setEight(){
    let x = 8;
    updateNumber(x);
}

function setNine(){
    let x = 9;
    updateNumber(x);
}

function setPlus(){
    let oper = "+";
    updateOperator(oper);
}

function setMinus(){
    let oper = "-";
    updateOperator(oper);
}

function setDiv(){
    let oper = "/";
    updateOperator(oper);
}

function setMultiply(){
    let oper = "*";
    updateOperator(oper);
}

function existDot(x){

    let lim = x.length;

    for ( let i = 0; i < lim ; i++)
        if ( x[i] == "." )
                return true;


    return false;

}

function setDot(){

    if(!isNumberPressed){
        firstValueString = "0.";
        document.getElementById("input_2").innerHTML = firstValueString;
    }
    
    if(!isFirstValue){ 

        if( !existDot(firstValueString) ){ 
            firstValueString = firstValueString.concat(".");
            document.getElementById("input_2").innerHTML = firstValueString;
        }
    }
    else{
        if( !existDot(secondValueString) ){
            secondValueString = secondValueString.concat(".");
            document.getElementById("input_2").innerHTML = secondValueString;
        }
    }

}

function setSign(){

    numberShow = numberShow * (-1);

    if(!isFirstValue)
        firstValueString = "";
    else
        secondValueString = "";
    
    updateNumber(numberShow);

}

function setDelete() {

    if(!isNumberPressed)
                  return 0;

    let aux = numberShow.toString();
    aux = aux.substring(0,aux.length - 1);
    numberShow = parseFloat(aux);

    if(isNaN(numberShow))
           numberShow = 0.0;

    if(!isFirstValue)
        firstValueString = "";
    else
        secondValueString = "";
    
    updateNumber(numberShow);

}

function setRestart(){

    firstValueString = "";
    secondValueString = "";
    firstValue = 0.0;
    secondValue = 0.0;
    isFirstValue = false;
    isSecondValue = false;
    isNumberPressed = false;
    isSecondPressed = false;

    numberShow = 0.0;

    result = 0.0;
    stringResult = "";
    lastOperator = "";

    document.getElementById("input_1").innerHTML = "";
    document.getElementById("input_2").innerHTML = "";

}

function setMessage(){

    setRestart();

    document.getElementById("input_1").innerHTML = "<span class=\"CE\">Acesta este un</span>";
    document.getElementById("input_2").innerHTML = "<span class=\"CE\">calculator !</span>";

}

function setEqual(){

    if(isNumberPressed && isSecondPressed){

        updateResult(lastOperator);
        document.getElementById("input_1").innerHTML = "";
        document.getElementById("input_2").innerHTML = result;
        
    }
    else {
        document.getElementById("input_1").innerHTML = "";
        document.getElementById("input_2").innerHTML = result;
    }

    numberShow = result;
    firstValue = result;
    stringResult = "";
    lastOperator = "";
    secondValueString = "";
    secondValue = 0.0;
    isSecondValue = false;
    isSecondPressed = false;

}

