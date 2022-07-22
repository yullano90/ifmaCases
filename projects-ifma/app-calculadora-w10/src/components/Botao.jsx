import React from 'react';
import './Botao.css';

export default function (props) {
    return <button className="botao" onClick={e => props.click(e.target.innerHTML)}> { props.valor }</button >
}