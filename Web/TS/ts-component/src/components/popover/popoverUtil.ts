import {PositionKind} from "../../common/kinds";
import {Data} from "popper.js";

export const positionToPlacement = (position: PositionKind | 'auto') => {
    switch (position) {
        case PositionKind.TOP_LEFT:
            return 'top-start';
        case PositionKind.TOP:
            return 'top';
        case PositionKind.TOP_RIGHT:
            return 'top-end';
        case PositionKind.RIGHT_TOP:
            return 'right-start';
        case PositionKind.RIGHT:
            return 'right';
        case PositionKind.RIGHT_BOTTOM:
            return 'right-end';
        case PositionKind.BOTTOM_RIGHT:
            return 'bottom-end';
        case PositionKind.BOTTOM:
            return 'bottom';
        case PositionKind.BOTTOM_LEFT:
            return 'bottom-start';
        case PositionKind.LEFT_BOTTOM:
            return 'left-end';
        case PositionKind.LEFT:
            return 'left';
        case PositionKind.LEFT_TOP:
            return 'left-start';
        case 'auto':
            return 'auto';
        default:
            return new Error(`Unexpected position: ${position}`);
    }
}

export const getPosition = (placement, index) => {
    return placement.split('-')[index]
}

export const getOppositePosition = (position) => {
    switch (position) {
        case 'top':
            return 'bottom'
        case 'bottom':
            return 'top'
        case 'left':
            return 'right'
        default:
            return 'left'
    }
}

/**
 *      |
 *  left|right
 * @param position
 */
export const isVerticalPosition = (position) => {
    return ['left', 'right'].indexOf(position) != -1
}

export const getAlignment = (alignment) => {
    switch (alignment) {
        case 'start':
            return 'left'
        case 'end':
            return 'right'
        default:
            return 'center'
    }
}

export const getTransformOrigin = (data: Data) => {
    const position = getPosition(data.placement, 0)
    const alignment = getPosition(data.placement, 1)
    return isVerticalPosition(position) ?
        `${getOppositePosition(position)} ${getAlignment(alignment)}` :
        `${getAlignment(alignment)} ${getOppositePosition(position)}`
}

