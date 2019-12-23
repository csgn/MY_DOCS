<template>
    <div>
        <h1>NewMemory Componenti</h1>
        <button @click="counter++">Press</button>
        <p> {{ counter }} </p>
    </div>
</template>

<script>
export default {
    data() {
        return {
            counter: 0,
        }
    },
    destroyed() {
        window.console.log("NewMemory Destroyed")
    },
    activated() {
        window.console.log("NewMemory Activated")
    },
    deactivated() {
        window.console.log("NewMemory Deactivated")
    },
}
</script>