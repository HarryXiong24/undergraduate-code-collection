import * as React from 'react'
import Demo from './pagination'
import {CodeView} from "../../components/codeview/codeview";

// @ts-ignore
const code = require('!!raw-loader!./pagination')

export default () => {
    return (
        <div>
            <Demo/>
            <CodeView code={code}/>
        </div>
    )
}
