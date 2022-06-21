import React from 'react';
import './Calculadora.css';
import Botao from '../components/Botao';
import Visor from '../components/Visor';

const estadoInicial = {
    valorVisor: '0',
    limparVisor: false,
    operacao: null,
    valores: [0, 0],
    posicaoAtual: 0
}

export default class Calculadora extends React.Component {
    state = { ...estadoInicial }

    //Definição do contrutor para trabalhar com estado da Calculadora;
    // STOP: Implementando Lógica 4/4        
    constructor(props) {
        super(props)
        this.limpaMemoria = this.limpaMemoria.bind(this)
        this.adicionaDigito = this.adicionaDigito.bind(this)

    }

    limpaMemoria() {
        this.setState({ ...estadoInicial })
        console.log("Limpando memória...")
    }

    adicionaDigito(n) {
        const limparVisor = this.state.valorVisor === '0' || this.state.limparVisor === true
        const valorAtual = limparVisor ? '' : this.state.valorVisor
        const valorVisor = valorAtual + n
        this.setState({ valorVisor, limparVisor: false })
        const i = this.state.posicaoAtual
        const novoValor = parseInt(valorVisor)
        const valores = [...this.state.valores]
        valores[i] = novoValor
        this.setState({valores})

        //Esse código pela a posiçao atual, transforma o valor em um inteiro;
        //Coloca o inteiro na posição atual e atualiza o valor de "valores";
        // STOP: Implementando Lógica 4/4
    }


    render() {
        return <div className="calculadora" >
            <Visor valor={this.state.valorVisor} />
            <div className="linha">
                <Botao valor="AC" click={this.limpaMemoria} />
                <Botao valor="x¹" click={this.defineOperacao} />
                <Botao valor="√" />
                <Botao valor="/" />
            </div>
            <div className="linha">
                <Botao valor="7" click={this.adicionaDigito} />
                <Botao valor="8" click={this.adicionaDigito} />
                <Botao valor="9" click={this.adicionaDigito} />
                <Botao valor="*" click={this.defineOperacao} />
            </div>
            <div className="linha">
                <Botao valor="4" click={this.adicionaDigito} />
                <Botao valor="5" click={this.adicionaDigito} />
                <Botao valor="6" click={this.adicionaDigito} />
                <Botao valor="-" click={this.defineOperacao} />
            </div>
            <div className="linha">
                <Botao valor="1" click={this.adicionaDigito} />
                <Botao valor="2" click={this.adicionaDigito} />
                <Botao valor="3" click={this.adicionaDigito} />
                <Botao valor="+" />
            </div>
            <div className="linha">
                <Botao valor="0" click={this.adicionaDigito} />
                <Botao valor="=" click={this.defineOperacao} />
            </div>
            <div className="linha">
                <Botao valor="by @yullano90" />
            </div>
        </div>
    }
}
