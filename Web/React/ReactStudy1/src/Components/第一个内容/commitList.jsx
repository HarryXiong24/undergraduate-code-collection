import React from 'react';
import CmtItem from './commitItems';

import cssItem from '../css/index.module.css';

export default class Box extends React.Component {

    constructor() {
        super();
        this.state = {
            CommitmentList: [
                {id: 1, user: "A", content: "a"},
                {id: 2, user: "B", content: "b"},
                {id: 3, user: "C", content: "c"},
                {id: 4, user: "D", content: "d"},
                {id: 5, user: "E", content: "e"},
            ]
        }
    }

    render() {
        return (
            <div className={cssItem.box}>
                <h1>这是评论列表组件</h1>
                {this.state.CommitmentList.map(
                    items => <CmtItem {...items} key={items.id}> </CmtItem>
                )}
            </div>
        )
    }
}