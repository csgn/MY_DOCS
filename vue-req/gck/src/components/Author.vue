<template>
    <div>
        <h1>Author Componenti</h1>
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
        window.console.log("Author Destroyed")
    },
    activated() {
        window.console.log("Author Activated")
    },
    deactivated() {
        window.console.log("Author Deactivated")
    },
}
</script>